#!/usr/bin/perl

my $command = "reload";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_reload {
        my %bot_message_hash = %{shift @_};
        my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

        $bot_object->SendJabberMessage($bot_message_hash{reply_to}, "$prefix" . "Client reloading...", $bot_message_hash{type});
	sleep 1;
        system("/etc/init.d/skynet restart");


	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	# my @output = ``;


	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
