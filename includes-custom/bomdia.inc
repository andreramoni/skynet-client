#!/usr/bin/perl

my $command = "bomdia";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_bomdia {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	# my @output = ``;

	$bot_object->SendJabberMessage($bot_message_hash{reply_to}, "$prefix" . "Bom dia $sender !", $bot_message_hash{type});


	if(-e "$custom_modules_dir/bomdia.conf") {
                require "$custom_modules_dir/bomdia.conf";
                @output = &bot_bomdia_custom(\%bot_message_hash, "$sender");
        }


	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
