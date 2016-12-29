#!/usr/bin/perl

my $command = "version";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_version {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	my @output = "Running version: $version";


	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
