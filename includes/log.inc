#!/usr/bin/perl

my $command = "log";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_log {
        my %bot_message_hash = %{shift @_};
        my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

        if ( @ARG[0] eq "" ){ @output = "log options: filename in /var/log/" }
        elsif( @ARG[0] eq "options" ) { @options=undef }
	else { 
		if(-f "/var/log/@ARG[0]") { 	@output = `tail /var/log/@ARG[0] 2>&1 ` }
		else { @output = "File not found" }
	}


	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
