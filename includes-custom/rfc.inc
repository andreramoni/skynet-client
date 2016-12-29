#!/usr/bin/perl

my $command = "rfc";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_rfc {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	# my @output = ``;

        if( @ARG[0] eq "" ){ @output = "rfc options: <string|update> "; }
        elsif ( @ARG[0] eq "update" ) { @output = "Updating RFC index..." ; system("$scripts_dir/rfc -i") }
        elsif ( @ARG[0] =~ /\d+/)  { @output = `$scripts_dir/rfc @ARG[0] | head -n 20` ; if( system("wget http://www.rfc-editor.org/rfc/rfc@ARG[0].txt -O /dev/null") == 0 ) { push(@output, "http://www.rfc-editor.org/rfc/rfc@ARG[0].txt") } }
        else  { @output = `$scripts_dir/rfc -s @ARG[0] | head -n 20` }


	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
