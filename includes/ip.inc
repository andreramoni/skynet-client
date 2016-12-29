#!/usr/bin/perl

my $command = "ip";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_ip {
        my %bot_message_hash = %{shift @_};
        my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = `ip addr sh|grep inet | expand | tr -s ' ' | cut -d' ' -f3`;

	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
