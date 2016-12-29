#!/usr/bin/perl

my $command = "df";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_df {
        my %bot_message_hash = %{shift @_};
        my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

        my @output = `df -lh -x tmpfs -x udev | grep -vE "Filesystem|udev" | awk '{print \$6" "\$5}' | sort -u | tr '\n' ','`;

	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
