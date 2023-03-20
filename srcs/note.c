PARSING



CHECKER
//- appliquer parsing sur les args
//-integrer makefile
//-integrer gnl de so long
-changer les vrai printf
-securiser les malloc
// -makefile qui relink
dans checker attention au return 0 dans le check sort


//-pause free
-Si aucun paramètre  spécifié, ne rien afficher et rendre l’invite de commande.
 //-mettre les arguments en atoi et stocker dans liste chainer
// -passer au fonctions de tries
//-Vérif que les entrées sont bien des nombres entier
-// min et max
//- telecharger tester +/-
//-split a chaque espace
-//transformer chaque case du tableau en int avec atoi , a chauqe boucle retourner error sur depasse int min
//-verifier chaque nombre si on a pas un ++ , --, et si c est min ou max
//-Stocker les entrées valides dans un tableau/liste chainee
//-En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
//-check doublons
//Affichage des résultats :
// Affichez les résultats triés sur la sortie standard., tout stocker dans un string av envoie au parsing
  //- join tous les arg dans une string
//multiple arg ;
 //- si arg n a pas de space , socker en arg 1 d ans une string
 //-attention 000
//- faire un retrait comme des 0 pour les + et -
 y a t il un nb d argument max ?
 -changer le retour de ft_parse ?
 -verif le retoru des entree vide

1			2			2			3			1   	  3
3			1			3			2			3         1
2			3			1			1			2    	  2

0         swap a    rotate rev     swap			swap	rotate
								 rotate rev	   rotate


//vo //
//find min ,         // parcourir tab_int si find min, return son index   1 en p3
//si min pas en p1 -> rotate jusqu q que min en top pile  ->  rotate index fois
//vo // fonction parcurur liste chainee / ou tableau et reparcour
//push a -> b
//swap a
//push b -> a


//si 2 element et pas dans l ordre , swap

//REVERSE C VERS LE BAS

//-mettre en tableau et verifier si il est deja trier avec bubble sort ou trier
//- obtenir la median en divisant size tab par 2
//-faire les fonction de tri pour les 3 premier element
//-placer dans les 2 pile chaque face du pivot
//-refaire un tableau puis 2 median en recursif

FICHIERS
//-.h
//-makefile
- run le tester

"element pile

a0	b0
a1	b1
a2	b2
a3	b3
a4	b4
"

FONCTION DE TRI
//\\ premier argument en haut de pile, premier arrive premier sorti //
//-codder les fonctions de tri suivante;

	//	-sa: swap haut a1 / a0
	//	-sb: '.'  '.'  b0 / b1
		-ss: '.' sa ET sb '.'

		//-pa: (recouvre a) place b0 SUR a0
		-pb: (recouvre b) place a0 SUR b

	//	-ra: A ROTATE UP
//		-rb: B ROTATE UP
		-rr: ra ET rb

//ATTENTION dans les rotate rajouter une condition si
//la pile est trop petite pour rotate , regler le probleme des 2 roatat a la suite qui bug

	//	-rra: A ROTATE DOWN
//		-rrb: B ROTATE DOWN
		-rrr: rra ET rrb

revoir le parsing pour qu il se run plus vite

FINALISATION
-norminette, changer le nom de mes listes au normes et virer les fonction de tri
-free
-checker les leaks avec arret prog en cours
remettre les printf en ft printf
securiser les malloc de type
if (!tab)
		ft_exit(pile_a, pile_b, 2);

void ft_rotate_reverse(t_list *list, list_first *list_f)
{
	int len;
	int i;

	i = 0;

	if (!list)
		return;
	len = ft_lst_size(list_f->first);
	while(list->next != NULL)
		list = list->next;
	list->next = list_f->first;
	list_f->first = list;

	while(i < len - 1)
	{
		list = list->next;
		i++;
	}
	list->next = NULL;
	ft_printf("\nrotate_reverse %s\n", "");
	ft_printlist(list_f->first);
	return;
}