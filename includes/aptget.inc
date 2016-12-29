#!/usr/bin/perl

my $command = "aptget";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_aptget {
        my %bot_message_hash = %{shift @_};
        my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

	my @output = undef;
        my @ARG = @_;

	if( -e "/etc/debian_version" ) {
		my $YESNO="no";
		if( @ARG[1] eq "yes" ){ $YESNO="yes" } else { $YESNO="no" }
	        if( @ARG[0] eq "" ){ @output = "aptget options: <update|upgrade>"; }
	        elsif( @ARG[0] eq "update") { 
			$bot_object->SendJabberMessage($bot_message_hash{reply_to}, "$prefix" . "Updating database...", $bot_message_hash{type});
			@output = `apt-get update` ;
		}
	        elsif( @ARG[0] eq "upgrade") { 
			@output = `apt-get upgrade --assume-$YESNO| tail -n 1 `;
		}
	}
	else { @output = "Not a debian distro !" }

	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
