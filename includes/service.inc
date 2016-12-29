#!/usr/bin/perl

my $command = "service";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_service {
        my %bot_message_hash = %{shift @_};
        my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;
	my $action = @ARG[1];
	if(@ARG[0] eq "") { @output = "service options: service <script> <stop|start|restart>" }
	elsif( -f "/etc/init.d/@ARG[0]" ) { @output = `/etc/init.d/@ARG[0] $action` }
	elsif( ! -f "/etc/init.d/@ARG[0]" ) { @output = "/etc/init.d/@ARG[0] nao existe" }

#        my @output = `date`;

	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
