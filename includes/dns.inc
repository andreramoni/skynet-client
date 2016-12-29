#!/usr/bin/perl

my $command = "dns";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_dns {
        my %bot_message_hash = %{shift @_};
        my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;
	if(@ARG[0] eq "") { @output = "dns options: dns <IP or hostname to resolve>" }
	else { 
		my @dns_servers = `cat /etc/resolv.conf | grep nameserver | cut -f2 -d ' ' | tr '\n' ' '`;
		@output = "Using @dns_servers: \n" . `host @ARG[0]` ;
	}

	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
