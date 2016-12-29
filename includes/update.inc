#!/usr/bin/perl

my $command = "update";
my $function = "bot_" . $command;
my $tmpfile = "/tmp/skynet.tgz" ;

$command_actions{$command}      = \&$function;

sub bot_update {
        my %bot_message_hash = %{shift @_};
        my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }


	my $SITE_VER=`curl http://skynet/version.txt`;
        my $MY_VER = $version;

	if ( $MY_VER < $SITE_VER ) { 
		$bot_object->SendJabberMessage($bot_message_hash{reply_to}, "$prefix" . "My version: $MY_VER, available version: $SITE_VER, action: UPDATE & RELOAD", $bot_message_hash{type});
		system("curl http://skynet/skynet-client.tgz > $tmpfile");
	        system("cd /etc ; tar zxf $tmpfile");
		&bot_reload(\%bot_message_hash);

	}
        else { @output = "My version: $MY_VER, available version: $SITE_VER, action: KEEP" }




	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
