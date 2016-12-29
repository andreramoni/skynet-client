#!/usr/bin/perl

my $command = "ping";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_ping {
        my %bot_message_hash = %{shift @_};
        my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

	my @output = undef;
        my @ARG = @_;

        if( @ARG[0] eq "" ){ @output = "PONG !"; }
        else { 
		$bot_object->SendJabberMessage($bot_message_hash{reply_to}, "$prefix" . "Starting 10 pings with 20s timeout...", $bot_message_hash{type});
		@output = `ping -w 20 -c 10 @ARG[0] -q | tail -n 2 | tr '\n' ' '` ;
	}

	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
