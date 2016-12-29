#!/usr/bin/perl

my $command = "ipcalc";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_ipcalc {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	# my @output = ``;

        if( @ARG[0] eq "" ){ @output = "ipcalc <IP|network>"; }
        else { @output = `ipcalc @ARG | grep ":" | /usr/bin/awk '{print \$1" "\$2}' ` }

	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
