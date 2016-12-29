#!/usr/bin/perl

my $command = "fortune";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_fortune {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	# my @output = ``;

        if( @ARG[0] eq "" ){ @output = "fortune options: <linux|debian> "; }
        elsif ( @ARG[0] eq "linux" ) { @output = `/usr/games/fortune  linux` }
        elsif ( @ARG[0] eq "debian" ) { @output = `/usr/games/fortune debian` }
        elsif ( @ARG[0] eq "science" ) { @output = `/usr/games/fortune science` }



	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
