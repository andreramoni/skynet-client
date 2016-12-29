#!/usr/bin/perl

my $command = "dell";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_dell {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	# my @output = ``;

#        if( @ARG[0] eq "tag" ){ $output = `echo  "@ARG[1]:" ; /usr/bin/curl --silent "http://www.dell.com/support/troubleshooting/br/pt/brbsdt1/servicetag/@ARG[1]\?s\=DHS" | grep "Guia Garantia" | sed 's|</b>|-|g' | sed 's|<[^>]*>||g' | sed 's|Consulte a Guia Garantia para obter detalhes.||' | tee /tmp/dell `; }
#        else { $output = "dell options: tag" }
        @output = "Dell closed the web query and now requires login.";


	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
