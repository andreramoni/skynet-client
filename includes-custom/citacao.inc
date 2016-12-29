#!/usr/bin/perl

my $command = "citacao";
my $function = "bot_" . $command;

$command_actions{$command}      = \&$function;






my @quotes = (
	"O melhor sistema eh aquele que voce conhece melhor (analista preguicoso). Pra empresa, o melhor analista eh o que esta disposto a aprender solucoes novas.", 
	"Cuidado... passarinho que acompanha morçego acorda de cabca pra baixo. (Evandro)",
	"Tudo aqui desmancha na boca. (Gabriel)",
	"Samu teu cu, buzios minha arte (Felipe Smith",
	"Eh pra fazer certo ou tem que funcionar ? (Piter Punk)",
	"Vickings sao cangaceiros, soh que europeus (sabio desconhecido)",
	"A vida eh um vai-e-vem que nao tem volta (Kuririn)",
	"Eh isso ai cumpade, quem come de tudo ta sempre mastigando (Sorin)",
	"Nao adianta por azulejo nas paredes se o piso eh de barro. (Neto)",
	"Eh o que eu falo: nao existe bullying, voce que eh otario. (Pereira)",
	"Meu quarto eh meu mundo. (Renan Eiras)",
	"Vejam o caso do Rubinho. Ele tem estrela. O problema eh que a estrela dele fica na bunda, quando ele senta no carro ela apaga (Hortencia)", 
	"A sua proatividade nao pode ser bengala para a falta de comprometimento dos outros. (Luciano)",
	"Tudo na vida eh passageiro, menos o motorista e o cobrador. (Kuririn)",
	"A beleza me persegue, mas eu sou muito mais rapido que ela. (Kuririn)",
	"Agora estou fazendo aula de canto, to evitando ficar no meio. (Kuririn)",
	"Quem pensa com o coracao corre serio risco de sofrer infarto cerebral. (Kuririn)",
	"A primeira vez que te vi tive a impressao de que nunca tinha te visto. (Kuririn)",
	"Amanha nao tem ninguem. Nao faz nem recebe chamada ha uma hora. (Claudio)",
	"Descobrir o verdadeiro sentido das coisas eh querer saber demais. (Kuririn)",
	"Mais vale um bebadis conhecidiss do que um alcoolatra anonimiss. (Mussum)",
	"Cacilds !! (Mussum)",
	"Nao sou faixa preta cumpadis, sou preto inteiris ! (Mussum)",
	"Eu vou me pirulitar ! (Mussum)",
	"Vudu eh pra jacu. (Pica-pau)",
	"Em todos esses anos nessa industria vital, esta e a primeira vez que isto me acontece. (Pica-pau)",
	"As aves tem na boca um unico dente, chamado bico. (Perolas do Enem)",
	"Q: Qual a principal funcao do esqueleto ? R: Conquistar o castelo de Grayskull. (Perolas do Enem)",
	"Nao ha coisa mais nociva que um idiota com iniciativa. (Matanza)",
	"O segredo do sucesso eh a moderacao, todo dia sim, o dia inteiro nao. (Matanza)",
	"Um idiota com uma ferramenta continua sendo um idiota.",	
	"Os otimistas dizem que vamos ter que nos alimentar de coco no futuro. Os pessimistas dizem que vai faltar coco.",
	"A vantagem de ser inteligente eh que podemos fingir que somos idiotas, enquanto que o contrario eh completamente impossivel. (Woody Allen)",
	"Liga pro cliente.... (Alcindo buneco)",
	"O buneco, nao ta vendo que nao eh assim que se faz isso ? (Alcindo buneco)",
	"Senhor, perdoai ! Ele nao sabe o que diz. (Marquinho para Alcindo)",
	"Em terra de olho, quem tem um cego ... errei.",
	"Grafico Melancia eh aquele todo verdinho por fora mas quando tu abre ta tudo vermelho por dentro. (Marcelo fala-fina)",
	"Pensar eh o trabalho mais dificil que ha. Talvez por isso tao poucas pessoas se engajem nele. (Henry Ford)",
	"Volta o cao arrependido, com suas orelhas bem fartas, com o seu osso ruido e o rabo entre as patas. (Chaves)",
	"Quem come tudo e nao divide nada acaba com a barriga inchada. (Chaves)",
	"DIIII  OOOOO   GOOOO !!! (Carol Falcao)",
	"O trabalho nao eh ruim. Ruim eh ter de trabalhar. (Seu Madruga)",
	"A vinganca nunca eh plena, mata a alma e a envenena. (Seu Madruga)",
	"A barriga eh a ultima que morre, seu esperanca. (Seu Madruga)",
	"PRE-RI-GO !! (Seu Madruga)",
	"Se a pratica levasse a perfeicao, meu cachorro ja tinha pego o rabo.",
	"Eu posso te dar o melhor guarda-chuva mas nao posso fazer parar de chover. (XSandro)",
	"Michael Jordan: 1, Isaac Newton: 0. (Nike)",
	"Eh claro que funciona Robin, voce eh que nao sabe mexer em porra nenhuma. (Batman)",
	"Um lider de talento deve ter a habilidade de fazer todos os seus oponentes parecerem pertencer a uma unica categoria. (Hitler)",
	"Nunca perguntarao a um vitorioso se ele contou a verdade. (Hitler)",
	"Alcool... a causa e a solucao para todos os problemas. (Homer)",
	"Cala a boca, Magda ! (Caco Antibes)",
	"Em toda a historia das especies, prevaleceram aqueles que aprenderam a colaborar e a improvisar com mais eficacia. (Darwin)",
	"O clube estava a beira do precipicio, mas tomou a decisao correta e deu um passo a frente. (Jogador de futebol)",
	"Tenho maior orgulho de jogar na terra onde Cristo nasceu. (Jogador de futebol ao desembarcar em Belem do Para)",
	"Socrates eh invendavel, inegociavel e imprestavel ! (Tecnico de futebol)",
	"Assiste depois mais um capitulo inedito de vale a pena ver de novo. (Galvao Bueno)",
	"A iniciativa eh o primeiro passo para o fracasso. (Homer)",
	"Eu nao deveria estar dirigindo... espera, eu nao deveria me dar ouvidos, eu estou bebado ! (Homer)",
	"Eu nao acredito em duendes. Eles sao muito mentirosos. ",
	"A culpa eh minha e eu a coloco em quem eu quiser ! (Homer)",
	"Se nao puder ajudar, atrapalhe. O importante eh participar. (Homer) ",
	"Eh facil reprovar uma ideia, dificil eh ter uma. (Homer)",
	"Nunca discuta com um idiota. Ele ira rebaixa-lo ate seu nivel e entao o derrotara com sua vasta experiencia. (Homer)",	
	"Acabou o amor. (Carlos Nogueira)",
	"Engracado eh Juca Chaves tomar chopp com nariz pra fora do copo. (Sorin)",
        "E Deus disse a noe: faz backup que eu vou formatar !",
	"Eu aproveitei mais o alcool do que ele se aproveitou de mim. (Churchill)",
	"Nao existe opiniao publica, existe opiniao publicada. (Churchill)",
	"Sucesso eh ir de fracasso em fracasso sem perder o entusiasmo. (Churchill)",
	"Pacificador eh aquele que alimenta um crocodilo esperando que ele o coma por ultimo. (Churchill)",
	"Quando fugir de um tigre, voce nao precisa correr mais que ele. So precisa correr mais que os outros.",
	"Por vezes os homens tropecam na verdade, mas a maioria se recupera e vai em frente. (Churchill)",
	"A coragem eh a primeira qualidade humana, porque eh a qualidade que garante as demais. (Churchill)",
	"Foco eh dizer nao. (Steve Jobs)",
	"As pessoas nao sabem o que querem ate mostrarmos a elas. (Steve Jobs)",
	"Se criar bons produtos fosse facil como assinar um cheque, a Microsoft teria grandes produtos. (Steve Jobs)",
	"640k eh suficiente para qualquer um. (Bill Gates)",	
	"As pessoas que sao loucas o suficiente para achar que podem mudar o mundo sao as que, de fato, mudam. (Steve Jobs)",
        "A maior licao da vida eh de que, as vezes, ate os tolos tem razao. (Churchill)",
        "Eh preferivel ser irresponsavel na verdade do que responsavel no erro. (Churchill)",
        "Um pessimista ve uma dificuldade em cada oportunidade; um otimista ve uma oportunidade em cada dificuldade. (Churchill)",
        "O que eu espero dos senhores eh que apos uma razoavel discussao, todos concordem comigo. (Churchill)",
        "Fanatico eh aquele nao muda de ideia nem de assunto. (Churchill)",
        "Poooorrraaa muleke !! Senta aih !! (magico Valadares)",
        "A forma mais eficaz de prever o futuro eh escreve-lo voce mesmo. (Churchill)",
        "Eu conheco Bruno Wallace (Sorin)",
        "O forno ta ligado, ta botando pao pra dentro (sorin em referencia ao claudio)",
        "Cade babai ? Cade babai ? (Uellington bebado)",
        "A inovacao eh o que diferencia um lider de um seguidor.",
        "O sapo nao lava o pe, nao lava porque nao quer. Ele mora la na lagoa, nao lava o pe porque nao quer.",
        "Oh vida, oh ceus, oh azar (Hardy)",
        "Nelsinho, boa tarde, Vsa excelencia esta trabalhando ? (Feitosa)",
        "Hmm... nao me veio nada agora.",
        "O abridor de garrafas nao eh nem um pouco complexo, no entanto eh ferramenta essencial pra todo butequeiro (Nicoletti).",
        "Nao sei que sou eu que estou usando muitas drogas ou se sao esses duendes que eu vejo que estao bebendo demais...",
        "A vida nao eh uma jornada na qual voce deva chegar sao e salvo ao caixao. (Ramoni)",
        "Qual o resultado da sua analise ? (Luciano)",
        "Que fazer ? (famosa duvida de Lenin)",
        "O homem eh um animal que nao deu certo (bebado sobre Darwin).",
        "A curiosidade eh mais importante que o conhecimento. (Einstein)",
        "A tradicao eh a personalidade dos imbecis. (Einstein)",
        "Quem nunca errou nunca experimentou nada novo. (Einstein)",
        "Nao sei com que armas a 3a guerra mundial sera lutada, mas a 4a sera com paus e pedras. (Einstein)",
        "Uma reuniao onde todos os presentes estao absolutamente de acordo, eh uma reuniao perdida. (Einstein)",
        "O casamento eh uma tentativa mal sucedida de extrair algo duradouro de um acidente. (Einstein)",
        "Especialista eh alguem que lhe diz uma coisa simples mas de maneira confusa, de tal forma que faz voce pensar que a confusao eh culpa sua. (Einstein)",
        "Especialista eh aquele que erra especificamente em poucos assuntos",
        "Teoria eh quando algo deveria funcionar e nao funciona. Pratica eh quando algo funciona mas nao se sabe o porque. Aqui temos teoria e pratica: nada funciona e ninguem sabe o porque.",
        "O problema do casamento eh a comunicacao. Ha comunicacao demais (Homer)",
        "Eh impossivel fazer algo a prova de idiotas. Eles sao muito inventivos.",
        "Sempre encontramos algo no ultimo lugar que procuramos. Obvio, porque depois que encontramos paramos de procurar.",
        "Pra quem nao tem pra onde ir, qualquer lugar serve. (Sorin)",
        "Ta reclamando igual puta na chuva. (Sorin)",
        "A cachaca vem da cana, e a cana vem da roca. O homem com duas mulheres uma dele a outra nossa. (Sorin)",

);







sub bot_citacao {
        my %bot_message_hash = %{shift @_};
	my $bot_object = $bot_message_hash{bot_object};
        my $fullsender = $bot_message_hash{'from_full'};
        my ($sender) = split(/\@/, "$fullsender");

        my @ARG = @_;
	my @output = undef;

	# if( @ARG[0] eq "" ){ my @output = "$command option: "; }
        # else { my @output = `true` }
	# my @output = ``;

	my @output = @quotes[rand(scalar(@quotes))];
	return @output;
}                                                                                                                                                                                                                      
                                                                                                                                                                                                                       
1;                                                                                                                                                                                                                     
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                                                                                                                                                                                                       
                                  
