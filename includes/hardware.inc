#!/usr/bin/perl

my $command = "hardware";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_hardware {
        my %bot_message_hash = %{shift @_};
        my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	my @output = `(  lshw | grep -E "product:|vendor:|serial:" | expand | tr -s ' ' |cut -f1 -d '(' | head -n 3; echo CPUs: ;  lscpu | grep ^"CPU(s)" | awk '{print $2}' ; cat /proc/cpuinfo | grep "model name" | expand | tr -s ' ' | cut -f2 -d: | sort -u   ; cat /proc/meminfo | grep MemTotal | expand | tr -s ' ' ; fdisk -l|grep "Disk /dev" | cut -f1 -d, ) | tr '\n' ';'`;


	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
