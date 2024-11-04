import sys

input = lambda : sys.stdin.readline().strip()
lis = lambda : list( map( int , input().split() ) )
sin = lambda : int( input() )
many = lambda : map( int , input().split() )

'''


+++++++++++******+==. :::::::-=+====------==:::..:+-........:..............:-==========++:....:--=========+=:....:=---==
+++++++++++++****+==. :::::::-=+==-=-----===:..:-=+:.......::.............::-==========++:....:---======-===:....:=-----
+++++++++++++***++-=. :::::::-=+=--------===:.:---=+=....:==++-.............-==========++:....:------==--===:....:=-----
+++++++++++++***+===. :::.:::--+=-------=-==:.....:==:.::-::.==-...........:-===========+:....:------==--==-:....:------
+++++++++++++++++=-=. ::....::-+=-------=-==:.....-==.......:==:...:.....-::-===--==-===+:....:----------==-:....:------
+++++++++++++++++=-=. :.....::-+=------=--==--=--==:.......:=-:.....:.::=-.:-===---==-==+:....:-----------==:....:------
+++++++++++++++++=-=. :.....::-+=-----=---==::::::.......:=-:::.:...===:...:------------=:....:-----------==:....:------
+++++++++++++++++=-=. :.....::-====--==---==:.::........-=:::::--..:=::::..:------------=:....:-------------:....::-----
+++++++++++++++++=-=. :..::.::-=*
+++++++++++++++++=-=. :..:+**=-+
+++++++++++++++++=-=. :::*
+++++++++++++++++=-=. :.-*+*****
+++++++++++++++++=-=. :::=+**
===++++++++++++++===. ::::-**
====================. :::::--=*
***
*****************+++: :::::----
*****************+=+: :::------+*
*****************+++: ::-------+
*****************+++: ::-------+*
*****************+++: ::-----=**+**
*****************+++: :-----==-++****
*****************+++: :--------+++++*%%
*****************+++: :---=*
******************+****%
************
**********
*****************++*+----------+***
******++++++++++++*+: .---:--+*++++*******==::.*%%%@@@%%%%%%%*
+++++========++==+++: .:---+
++===------------+=+: :--++=---=++=+++=++*=-::+@%%@@@@@@@@@%%=+@%%@@%@+*%%%@%%%
+=====--==---=-+
=+===---=---+*
==-==---=--+*
++--==---+*+**+==+++- .-::::---=+====+*%
==--=---=+=++++==+++- .-:::::--=*===*%%%%
==--=--++--------=+=- .-:::::-=
+==--=-+=--------=+=- .-::::-*
++=-==--------=-=+++- .-:::=*+-=++++
++=--=--------==-=+=- .::-++---=++=*%%%
=+=--==---====++++++- .--
=+=------===+****++=- .-:-:--===+=+
===------=======-=+=- .--:=
-==--==-========++++===::-
============+=+=+++==:--:+*
==================++- .-:-+%
=================+++= .-::=-*
+++++++++++++++++***= .-:--+
           ...........:-:::+
:::::-------------=---=-----=+=+++*@@@@@@@@@@@@@@@@@@@@@%%
::::::-----------------------==++++@@@@@@@@@@@@@@@@@%%@@%%
++++++**********************++***++*%@@@@@@@@@@@@@@@@@@@%
*********************************

%
%
%


+++++++++++***********************
++++++++++++++++++++++++++++*********+****
++++++++++++++++++++++++++++++++*******+*@@@
+++++++++++++++++++++++++++++++++++***+++%@@@%***++=========*@@@@@@@@@@
+++++++++++++++++++++++++++++++++++++*+++%@@@@
++++++++++++++++++++++++++++++++++++++*
++++++++++++++++++++++++++++++++******+++*
+++++++++++++++++++++++++++*+**
+++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++
++++++++++++++++++++++++++===-+%%@*%**
++++++++++++++++++++++++====--=@%
+++++++++++++++++++++++===-----*%%%@%@@%%%@%
++++++++++++++++++*++====----=+**@%%%@@@@%%@@@%@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@%%%*=-:...  .   .  :*=-:::---=:
++++++++++++++++**+++===---=+++*%@%%%%%@%@@@%@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
++++++++++++++++*+*+*+=-=+++++*@@@%%%%%%@@@@@@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%- ............ . .==---=--=......
+++++++++++++++++=*=+===++++*+%@@@%%%%%@@@@@@@@@@@@%%@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%: .......... ...  :+=:=----.....
+++++++++++++*++=+=+=-+++**+++%@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%- .............. . =----:--....
+++++++++++++*+*+***=+**++*++*@@@@@@@@@@@@@@@@%%%@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
+++++++++++++*
++++++++++++****+*
+++++++++++++**
+++++++++++++**+**
+++++++++++++++*+
+++++++++++++++++++********+****%@@@@@@@@@@@@@@@%@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%@%%%%@%*+***
+++++++++++**********************%@@@@@@@@@@@@@%%@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@%%%*+++++********
+++++++++++***********************
++++++++++**************************
++++*+++*******************************
++*************************************+*
++***++*******************************++**

'''


import bisect
from math import ceil , sqrt , factorial , log
from collections import deque
from bisect import bisect_left




'''
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGP5YYJ???7777!!7?JY5PGBBGGGGGGGGGGGGGGGGGGGGGGGGGGBBBGGGGGGGG
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGBGGGGP5YJJJJ???77!!~~~~~~~~~!7?5PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGP5YJJJ??????????77!!~~~~^^^^^^^~7YGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
BBBBBBBBBBBBBBBBBBBBBGGGGBGGGBPYJ???????????JJJ???7!!~~^^^^^^^^:::~JPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
BBBBBBBBBBBBBBBBGGGGGGGGGGGBG5J????7?77?????JJJJJJ?77!!~~^^::::::...~JGGGPGGGGGGGGGGGGGGGGGGGGGGGGGG
BBBBBBBBBBBBBBBBGGGGGGGGGGGPJ?7777777!777????JJJJJJ??77!~~^::::.......~5GPGGPPGGGGGGGGGGGGGGGGGGGGGG
BBBBBBBBBBBBBBBGGGGGGGGGGB5?77!7!!~~~!!7777????JJJJJJJ?7!!~:..   ..    .!GGPGGGGPGGGGGGGGGGGGGGGGGGG
BBBBBBBBBBBBBBBGGGGGGGGGGP?77!!!!~^^~~!!!77777??JJYYYYJJ77~:.            !GPGGGGPPGGPGGGGGGGGPPGGGGG
BBBBBBBBBBBBBBGGGGGGGGGGP???7!~!!~~~~~!!!!777???JJYYYYYJ?77^..:...        ?GGGGGGPPPPGGGGGGGGPGGGGGG
BBBBBBBBBGGGGGGGGGGGGGGGJ?77!!!!!!!!!!77777?????JJJJJJJ?!~~~:^^^..        ^GGPPPPPPPPPGGGGPGGPGGGGGG
BBBBGGGGGGGGGGGGGGGGGGGP??777!!!!!77777777777777?JJJ???77!~^^^^:.         .5GGPPPPPPPPPPPPPPPGGGGGGG
BBBGGGGGGGGGGGGGGGGGGGGJ7?777!!!!777!7777??????77???JJJ??77!~^^...        .7GPPPPPPPPPPPPPPPPPPPPPPG
BBBGGGGGGGGGGGGGGGGGGGP????7!!!!!!!!!!7777?J?????7??JJJJYYJJ?!~:..        .:PPPPPPPPPPPPPPPPPPPPPPPP
BBBBGGGGGGGGGGGGGGGGGG5?7??7!!!777777?JJJJJJ??7JJJJJY55YYYY55Y?!~:.    .  ..JGGPPPPPPPPPPPPPPPPPPPPP
GGBGGGGGGGGGGGGGGGGGGGJ???7?J555GGBBBB
GGGGGGGGGGGGGGGGGGGGGGJ???JYPGB&&&&&&&&
GGGGGGGGGGGGGGGGGPPPGP????J5G
GGGGGGGGGGGGGGGGPY??JJ??77?5GGPJP
GGGGGGGGGGGGGGGG5GG7!~??7!7777JYYPGGGGGP5JJ???YP
BBGGGGGGGGGGGGGG55Y~!!??7!!!!!!7?JY555YJ77????!.?BBBGPPPPPPPP5Y?!~~~~^:.....~~!!5GJYPGPPPPPPPPPPPPPP
BGGGGGGGGGGGGGGG5Y?!?5JJ77!!!!!!777777!!!7????~. :7JP5YYJJYYJ?77!~^^:...::::!!^.~PJ5PPPPPPPPPPPPPPPP
GGGGGGGGGGGGGGGG577J5Y7J?7!!!!!!!!!!!!777??77?7^.  .!??77!~!!77??7~^:.:::::.:Y5J~J?YGPPPPPPPPPPPPPPP
GGGGGGGGGGGGGGGGP?7JY!!Y?777!!~~~~!77J?7??7!77?7:....?YJ??7!^~~^~~!!~~^:::..:!55?7?5PPPPPPPPPPPPPPPP
GGGGGGGGGGGGGGGGGY7?YJ!J?7777!!!!7?Y55J???77?JJY7!!~^:P5YYYJ7!!~^^~~!~^:::.^7YPP7!JPPPPPPPPPPPPPPPPP
GGGGGGGGGGGGGGGPG5?77?7??77??777?YJYJJ?YPBBP5PPGG
GGGGGGGGGGGGGGGPGGJ7!!7??777??7JY77?777?YPGP5GG
GGGGGGGGGGGGGGGPGGGJ!!~?J??????Y???JJYYYY5GGPGGB
GGGGGGGGGGGGGGGGPGGP5Y55J??7???YJY5555555PPPPGPGGB
GGGGGGGGGGGGGGGGPGGGPGGGJ??????JJYY5P5YYYY5PGBBGPGGBBBBBBBGGPJ~57G5?!?!^:7PPPPPPPPPPPPPPPPPPPPPPPPPP
GGGGGGGGGGGGGGGGPGGGGGGGY???JJ?JJ5PPBBP5YY5PPGGGPGGBBBB
GGGGGGGGGGGGGGGGGGGGGGGGPJ???J?JJ5PG555YYPPPPGGGBB
GGGGGGGGGGGGGGGGGGGGGGGPP5YYJJJJYYJJ?????JJY55PPGGGG5JY5P55555J!PGY?JJ7!YPPPPPPPPPPPPPPPPPPPPPPPPPPP
GGGGGGGGGGGGGGGPPPPGGGGPPPP55YYYJJ??777??JYPPGGGGGPPY7777??JJJ!?G5Y5YJ!^5PPPPP5PPPPPPPPPPPPPPPPPPPPP
GGGGGGGGGGGGGGGGGGGPPPPPPGP555YYJYY?????JY55PGGGGGGGP55YJJ?YJ7!?YYYYJ7~^5PPPPPPPPPPPPP555555PPPPPPPP
GGGGGGGGGGGPPGGGGGGPPPPPPG5JY5555Y5JJJJ??J5PPGGGGBGGPPPP5J?J?!!7????7!^~PP5PPPPPPPPPPPPP5555PPPPP555
GGGGGGGGGGGPGGGGPPGPPPPPPPPJJYYY555YJJJ??JJJY555PPPPPPP5JJ??7~!!77777!^!PP555555555555555555555PPPPP
GGGGGGGGGGGPGGGGPPPPPPPPPGPJJJJYPP5YJYYYJJJYYY55P5P5PPPYJ?!!!!777777!!^755PPPPPPPPPGGGGGBBBBBB
GGGGPGGPPGGGGGGGGPPPPPPPPPPJJJJY5PG5JJY5YYY555PP5PPPGGP5Y?7!!7???J?7!~^75Y5
GGGGPPGGGPPGPPGGPPPPPPGPJY
GGGPPPPGPPPPPPPPGGGGGB5~^!GB5JYYY55PBBGGGGGGPPPGGGGBBBBBBGPBBBPYJJ?7!^^Y
GGBB
GG
GB
GB&&&&&&&&&@&&G:  . . .~^::::::::!5GBBBBGPPPGBB
GB&&&&&&@@&&
G
G

'''




alp = "abcdefghijklmnopqrstuvwxyz"
ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

mod = 10 ** 9 + 7
INF = 10 ** 18





def solve() :
    n , k = map( int , input().split() )
    s = list( input() )
    d = {}
    p = [0]*26

    for i in range(n):
        x  = ord(s[i]) - ord('a')
        while x and k and p[x]!=1:
            p[x] = 1
            x-=1
            k-=1
    
    ans = ''
    for i in range(n):
        x =  ord(s[i])-ord('a')
        while x and p[x]==1:
            x-=1
        ans+=alp[x]

    print(ans)




testisisisisisis = int( input() )
for testis in range( testisisisisisis ) :
    solve()
