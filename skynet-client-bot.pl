#!/usr/bin/perl

use Sys::Syslog;
use Net::Jabber::Bot;
#use Log::Log4perl qw(:easy); 
our $conf_dir = "/etc/skynet-client";
our $modules_dir = $conf_dir . "/includes";
our $custom_modules_dir = $conf_dir . "/includes-custom";
our $scripts_dir = $conf_dir . "/scripts";
our $prefix = "";
our $log_id = "skynet-client";
our $loop_timeout = 10;

require "/etc/skynet-client/skynet.conf";
require "/etc/skynet-client/version.conf";

openlog("skynet-client-bot","ndelay,pid","local0");

my %alerts_sent_hash;
my %next_alert_time_hash;
my %next_alert_increment;
our %command_actions;


my %forums_and_responses;
foreach my $forum (@forums) {
    my $responses = "bot:|hey you|"; # Note the pipe at the end indicates it will act on all messages
    my @response_array = split(/\|/, $responses);
    push @response_array, "" if($responses =~ m/\|\s*$/);
    $forums_and_responses{$forum} = \@response_array;
}

# General includes:
opendir(DH,"$modules_dir");
@mods=readdir(DH); closedir(DH); @mods=grep(/\.inc$/,@mods);
print ("Loading includes: ");
foreach $mod (@mods){ require "$modules_dir/$mod"; $modules .=  "$mod "; }


logsay("Starting Skynet client bot version $version");
logsay("Loaded includes: $modules");

# Custom includes:
logsay("Custom modules to load: @custom_includes");
foreach $mod (@custom_includes){
        if ( -e "$custom_modules_dir/$mod.inc") { require "$custom_modules_dir/$mod.inc"; $custom_modules .=  "$mod "; }
}


logsay("Loaded custom includes: $custom_modules");
foreach(keys(%command_actions)){ $commands .= "$_ " }
logsay("Suported commands: $commands");



sub create_bot {
                our $bot = Net::Jabber::Bot->new({
                                 server => "$server"
                                , conference_server => "conference.$server"
                                , port => $port
                                , username => $username
                                , password => $password
                                , alias => $alias
                                , safety_mode => 1
                                , tls => 1
                                , message_function => \&new_bot_message
                                , background_function => \&background_checks
                                , loop_sleep_time => 10
                                , process_timeout => 10
                                , forums_and_responses => \%forums_and_responses
                                , ignore_server_messages => 1
                                , ignore_self_messages => 1
                                , out_messages_per_second => 100
                                , max_message_size => 100000
                                , max_messages_per_hour => 100000
                            });
};


# MAIN LOOP
sub main_loop {
while(){
	while(not defined($bot)) {
		logsay("(connection) Connecting...");
		eval { &create_bot };
		sleep $loop_timeout;
	}
	logsay("(connection) Connected !");
	&logsay("(connection) Starting listener.");
	sleep 1;
	&logsay("(connection) Bot ONLINE !");
	$bot->Start();
};
};
main_loop;





##############################
# Basic functions:
sub background_checks {
    #my $bot= shift;
    my $counter = shift;
    my $const = $bot->IsConnected();
	if($const eq "9999999999") {
		&logsay("(connection) Disconnected.");
		$bot->Disconnect;
		undef($bot);
	  	main_loop;	
#		#system("/etc/init.d/skynet restart");
#		$bot->Disconnect;		
#		&create_bot();
#		$bot->Start;
	}

}

sub new_bot_message {
	my %bot_message_hash = @_;

    # Who to speak to if you need to.
    $bot_message_hash{'sender'} = $bot_message_hash{'from_full'};
    $bot_message_hash{'sender'} =~ s{^.+\/([^\/]+)$}{$1};
	my $sender = $bot_message_hash{'sender'};
	next if ($sender eq $username);

	my($command, @options) = split(' ', $bot_message_hash{body});
	$command = lc($command);
	
	# Special:
	if( $bot_message_hash{body} =~ /^bom dia/i ) { $command = "bomdia" ; shift(@options) }
	if( $bot_message_hash{body} =~ /^apt-get/i ) { $command = "aptget" }

	#my %command_actions;
	&logsay("(listener) $bot_message_hash{'from_full'}  said: $command @options\n");


#  	$command_actions{'subject'}  = \&bot_change_subject;
#   	$command_actions{'nslookup'} = \&bot_nslookup;
#	$command_actions{'say'}      = \&bot_say;
#	$command_actions{'help'}     = \&bot_help;
	$command_actions{'unknown_command_passed'} = \&bot_unknown_command;
#	sleep 1;
	if(defined $command_actions{$command}) {
		#$command_actions{$command}->(\%bot_message_hash, @options);
		&run_function(\%bot_message_hash, $command, @options);
	} else {
		$command_actions{'unknown_command_passed'}->(\%bot_message_hash, @options);
	}
}


sub run_function {
        my %bot_message_hash = %{shift @_};
        $bot_message_hash{'sender'} = $bot_message_hash{'from_full'};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

	my $command = shift;
        my @options = @_;

        &logsay("(runner/$command/$fullsender) input:  @options");

        foreach ( $command_actions{$command}->(\%bot_message_hash, @options) ){
                &logsay("(runner/$command/$fullsender) output: $_");
                my $bot_object = $bot_message_hash{bot_object};
                $bot_object->SendJabberMessage($bot_message_hash{reply_to}, "$prefix" . $_, $bot_message_hash{type});
        }
	
}








sub bot_change_subject {
    my %bot_message_hash = %{shift @_};
    my $new_subject = join " ", @_;
    
    my $bot_object = $bot_message_hash{bot_object};
    my $reply_to   = $bot_message_hash{reply_to};
    
    if($bot_message_hash{type} ne 'groupchat') {
        $bot_object->SendJabberMessage($reply_to
                                       , "Sorry, I can't change subject outside a forum!"
                                       , $bot_message_hash{type});
        WARN("Denied subject change from $reply_to ($new_subject)");
        return;
    }

    $bot_object->SendGroupMessage($reply_to, "Setting Forum subject to: $new_subject");
    $bot_object->SetForumSubject($reply_to, $new_subject);
    return;
}

sub bot_nslookup {
    my %bot_message_hash = %{shift @_};
    my $host = CleanInput(shift @_);

    my $bot_object = $bot_message_hash{bot_object};
    my $reply_to   = $bot_message_hash{reply_to};

	if(!defined $host) {
	    $bot_object->SendJabberMessage($reply_to
                                       , "Stop screwing around $bot_message_hash{sender}!"
                                       , $bot_message_hash{type});
	    return;
	}

    my $output = `/usr/sbin/nslookup $host 2>&1`;
    $bot_object->SendJabberMessage($reply_to, $output, $bot_message_hash{type});
    
}


sub bot_say {
    my %bot_message_hash = %{shift @_};
    my $to_say = join " ", @_;
    
    my $bot_object = $bot_message_hash{bot_object};

    $bot_object->SendJabberMessage($bot_message_hash{reply_to}
                                   , $to_say
                                   , $bot_message_hash{type});
}

sub bot_help {
    my %bot_message_hash = %{shift @_};
    my @options = @_;
    
    my $bot_object = $bot_message_hash{bot_object};
    my $reply_to   = $bot_message_hash{reply_to};
    my $message_type = $bot_message_hash{type};

    $bot_object->SendJabberMessage($reply_to
                                   ,  "I know how to do the following: nslookup <host>, say, "
                                    . "subject <new sub>"
                                   , $message_type);
}

sub bot_unknown_command {
    my %bot_message_hash = %{shift @_};
    my @options = @_;
    
    my $bot_object = $bot_message_hash{bot_object};
    my $reply_to   = $bot_message_hash{reply_to};
    my $message_type = $bot_message_hash{type};

    # Don't get confused about vague addresses empty messages
    return if(length $bot_message_hash{bot_address_from} <= 2);

    $bot_object->SendJabberMessage($reply_to
                                   , "Sorry $bot_message_hash{sender}, I don't know what you're asking me."
                                   , $message_type);
}

                           
sub CleanInput {
    my $string = shift;
    my $revised_string = $string;

    $revised_string =~ s{[\>\<\&\n\r;]}{}g; # Strip things that would allow enhanced commands.
    $revised_string =~ s/[^ -~]//g; #Strip out anything that's not a printable character

    return if($string ne $revised_string); # Error!
    return $string;
}


