#!/usr/bin/perl

my $command = "nagios";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_nagios {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command options "; }
        # else { my @output = `true` }
	# my @output = ``;

	if( @ARG[0] eq "status" ){ @output = `$scripts_dir/check_nagios.sh @ARG[1]`; }
        elsif ( @ARG[0] eq "" )  { @output = "$command options: status [hostgroup]" }


	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
