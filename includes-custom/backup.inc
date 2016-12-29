#!/usr/bin/perl

my $command = "backup";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;

sub bot_backup {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	# my @output = ``;

        @output = `echo -n "Running:" ; /usr/bin/php /etc/zabbix/externalscripts/backup_run.php; echo -n "Pending:" ; /usr/bin/php /etc/zabbix/externalscripts/backup_pen.php; echo -n "Waiting:" ; /usr/bin/php /etc/zabbix/externalscripts/backup_wai.php; echo -n "Queue:" ; /usr/bin/php /etc/zabbix/externalscripts/backup_que.php;`;  

	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
