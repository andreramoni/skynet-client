#!/usr/bin/perl

my $command = "email";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_email {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

        if( @ARG[0] eq "mailq" ){ @output = `/usr/bin/mailq | tail -n 1 | /usr/bin/awk '{print \$5 }' | tr -d '.' `; }
        else { @output = "opcoes: mailq" }

	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
