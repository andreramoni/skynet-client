#!/usr/bin/perl

my $command = "rss";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_rss {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	# my @output = ``;

        if( @ARG[0] eq "" ){ @output = "rss options: <slashdot|kernel|lxer> "; }
        elsif ( @ARG[0] eq "slashdot" ) { @output = `/usr/bin/rsstail -u http://rss.slashdot.org/Slashdot/slashdot -1 -n5 -l -H -r  ` }
        elsif ( @ARG[0] eq "kernel" ) { @output = `/usr/bin/rsstail -u https://www.kernel.org/feeds/kdist.xml -1 -n5  -H -r` }
        elsif ( @ARG[0] eq "lxer" ) { @output = `/usr/bin/rsstail -u http://lxer.com/module/newswire/headlines.rss -1 -n5  -l -H -r` }



	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
