#!/usr/bin/perl

my $command = "firewall";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_firewall {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	# my @output = ``;

        if( @ARG[0] eq "" ){ @output = "firewall options: libera <IP>, reload"; }
        elsif( @ARG[0] eq "libera" ){   @output[0] = "IP liberado por 1h.";
					my $tmpfile = "/tmp/fwrule.skynet";
					open(FH,">$tmpfile");
					print FH "iptables -I FORWARD -j ACCEPT -s @ARG[1] \n";
                                        print FH "iptables -I FORWARD -j ACCEPT -d @ARG[1] \n";
                                        print FH "iptables -I INPUT -j ACCEPT -s @ARG[1] \n"; 
					print FH "sleep 3600 \n";
					print FH "iptables -D FORWARD -j ACCEPT -s @ARG[1] \n";
                                        print FH "iptables -D FORWARD -j ACCEPT -d @ARG[1] \n";
                                        print FH "iptables -D INPUT -j ACCEPT -s @ARG[1] \n"; 
                                        print FH "rm $tmpfile \n"; 
					close(FH);
					system("/bin/sh $tmpfile &");
					
					}
        elsif( @ARG[0] eq "reload" ){ @output = "Regras recarregadas."; system("/etc/init.d/firewall restart"); }


	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
