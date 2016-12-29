#!/usr/bin/perl

my $command = "transito";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_transito {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	# my @output = ``;

        if( "@ARG" eq "ponte" ){ 
		@output = `/usr/bin/curl --silent https://twitter.com/transitonaponte|grep "travessia"| cut -f2 -d'>' | head -n1 |  sed 's|</b>|-|g' | sed 's|<[^>]*>||g'`; 
	}
        elsif( "@ARG" eq "reboucas" ){ 
		@output = `/usr/bin/curl --silent https://twitter.com/oglobo_vairio| grep -Ei "rebou.as" | head -n1 | cut -f2 -d">" | cut -f1 -d"<"`; 
	}
        elsif( "@ARG" eq "linha amarela" ){ 
		@output = `/usr/bin/curl --silent https://twitter.com/LinhaAmarelaRJ| head -n1 | cut -f2 -d">" | cut -f1 -d"<"`; 
	}
        else { @output = "transito options: ponte, reboucas, linha amarela" }


	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
