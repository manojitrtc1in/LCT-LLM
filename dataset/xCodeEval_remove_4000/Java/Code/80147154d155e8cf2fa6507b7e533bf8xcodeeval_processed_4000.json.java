import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Robots{

    static BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {

        String linea;
        linea = input.readLine();
        int casos = Integer.parseInt(linea);

        while(casos > 0){
            StringBuilder str = new StringBuilder(input.readLine());
            int U = 0,D = 0,R = 0,L = 0;
            for(int i = 0 ; i < str.length() ; i ++ ){
                char letra = str.charAt(i);
                if(letra ==  'U'){
                    U++;
                }

                else if(letra ==  'D'){
                    D++;
                }
                else if(letra ==  'R'){
                    R++;
                }
                if(letra ==  'L'){
                    L++;
                }
            }

            if(U > D){
                U = D;
            }

            else{
                D = U;
            }

            if(R > L){
                R = L;
            }

            else{
                L = R;
            }

            if(U == 0 && R > 1){
                R = 1;
                L = 1;
            }
            else if(R == 0 && U > 1){
                U = 1;
                D = 1;
            }
            
            int movimientos = U+D+R+L;
            System.out.println(movimientos);

            while(U > 0){
                System.out.print("U");
                U--;
            }
            while(L > 0){                
                System.out.print("L");
                L--;
            }
            while(D > 0){
                System.out.print("D");
                D--;
            }
            while(R > 0){
                System.out.print("R");
                R--;
            }
            System.out.print("\n");

            casos--;
        }

        
        
    }

}

interface Robot{

    public String[] movimientos(StringBuilder U , StringBuilder D , StringBuilder R, StringBuilder L);


}

 class id0 implements Robot{

    public String[] movimientos(StringBuilder U , StringBuilder D , StringBuilder R, StringBuilder L){
            int cantidad_U = U.length();
            int cantidad_D = D.length();
            int cantidad_R = R.length();
            int cantidad_L = L.length();

            int id1 = 0;

    
            if(cantidad_U > cantidad_D){
                cantidad_U = cantidad_D;
            }
    
            else{
                cantidad_D = cantidad_U;
            }
    
            if(cantidad_R > cantidad_L){
                cantidad_R = cantidad_L;
            }
    
            else{
                cantidad_L = cantidad_R;
            }

            

            if(cantidad_U == 0 && cantidad_R > 1){
                cantidad_R = 1;
                cantidad_L = 1;
            }
            else if(cantidad_R == 0 && cantidad_U > 1){
                cantidad_U = 1;
                cantidad_U = 1;
            }

            id1 = cantidad_U + cantidad_D + cantidad_L + cantidad_R;

            String Us = U.subSequence(0, cantidad_U).toString();
            String Ds = U.subSequence(0, cantidad_D).toString();
            String Rs = U.subSequence(0, cantidad_R).toString();
            String Ls = U.subSequence(0, cantidad_L).toString();
        
            
            String[] retorno = {Integer.toString(id1),Us,Ds,Rs,Ls};
            return  retorno;
    }

}

class saltador{
    public String[] movimientos(StringBuilder U , StringBuilder D , StringBuilder R, StringBuilder L){
        

        int cantidad_U = 0;
        int cantidad_D = 0;
        int cantidad_R = 0;
        int cantidad_L = 0;

        int id1 = U.length() + D.length() + R.length() + L.length();

        for(int i = 0 ; i <= U.length() ; i++){
            if(U.charAt(i) ==  '1'){
                cantidad_U++;
            }

            else{
                cantidad_U += 2;
            }

        }

        for(int i = 0 ; i <= D.length() ; i++){
            if(U.charAt(i) ==  '1'){
                cantidad_D++;
            }

            else{
                cantidad_D += 2;
            }

        }
        for(int i = 0 ; i <= R.length() ; i++){
            if(U.charAt(i) ==  '1'){
                cantidad_R++;
            }

            else{
                cantidad_R += 2;
            }

        }
        for(int i = 0 ; i <= L.length() ; i++){
            if(U.charAt(i) ==  '1'){
                cantidad_L++;
            }

            else{
                cantidad_L += 2;
            }

        }
        

        

        

        int resta = cantidad_U - cantidad_D;
        while(resta != 0){
            

            if(resta >= 2 || resta <= -2){
                

                if(cantidad_U > cantidad_D){
                    if(U.indexOf("2")!= -1){
                        int index = U.indexOf("2");
                        if (index == 0){
                             U = U.delete(0, 1);
                             id1 --;
                        }
                        else if (index == U.length()){
                            U = U.delete(index, index);
                            id1 --;
                        }
                        else{
                            U = U.delete(index-1,index+1);
                            id1 --;
                        }
                    }
                    else{
                        int n = 2;
                        while(n > 0){
                            int index = U.indexOf("1");
                            if (index == 0){
                                U = U.delete(0, 1);
                                id1 --;
                            }
                            else if (index == U.length()){
                                U = U.delete(index, index);
                                id1 --;
                            }
                            else{
                                U = U.delete(index-1,index+1);
                                id1 --;
                            }
                        }
                    }
                }
                

                else{
                    if(D.indexOf("2")!= -1){
                        int index = D.indexOf("2");
                        if (index == 0){
                            D = D.delete(0, 1);
                            id1 --;
                        }
                        else if (index == D.length()){
                            D = D.delete(index, index);
                            id1 --;
                        }
                        else{
                            D = D.delete(index-1,index+1);
                            id1 --;
                        }
                    }
                    else{
                        int n = 2;
                        while(n > 0){
                            int index = D.indexOf("1");
                            if (index == 0){
                                D = D.delete(0, 1);
                                id1 --;
                            }
                            else if (index == D.length()){
                                D = D.delete(index, index);
                                id1 --;
                            }
                            else{
                                D = D.delete(index-1,index+1);
                                id1 --;
                            }
                        }
                    }
                }

            }
            

            else{
                

                if(cantidad_U > cantidad_D){
                    if(U.indexOf("1")!= -1){
                        int index = U.indexOf("1");
                        if (index == 0){
                            U = U.delete(0, 1);
                            id1 --;
                        }
                        else if (index == U.length()){
                            U = U.delete(index, index);
                            id1 --;
                        }
                        else{
                            U = U.delete(index-1,index+1);
                            id1 --;
                        }
                    }
                    else{
                        int index = U.indexOf("2");
                        if (index == 0){
                            U = U.delete(0, 1);
                            id1 --;
                        }
                        else if (index == U.length()){
                            U = U.delete(index, index);
                            id1 --;
                        }
                        else{
                            U = U.delete(index-1,index+1);
                            id1 --;
                        }

                        index = D.indexOf("1");
                        if (index == 0){
                            D = D.delete(0, 1);
                            id1 --;
                        }
                        else if (index == D.length()){
                            D = D.delete(index, index);
                            id1 --;
                        }
                        else{
                            D = D.delete(index-1,index+1);
                            id1 --;
                        }

                    }
                }
                

                else{
                    if(D.indexOf("1")!= -1){
                        int index = D.indexOf("1");
                        if (index == 0){
                            D = D.delete(0, 1);
                            id1 --;
                        }
                        else if (index == D.length()){
                            D = D.delete(index, index);
                            id1 --;
                        }
                        else{
                            D = D.delete(index-1,index+1);
                            id1 --;
                        }
                    }
                    else{
                        int index = D.indexOf("2");
                        if (index == 0){
                            D = D.delete(0, 1);
                            id1 --;
                        }
                        else if (index == D.length()){
                            D = D.delete(index, index);
                            id1 --;
                        }
                        else{
                            D = D.delete(index-1,index+1);
                            id1 --;
                        }

                        index = U.indexOf("1");
                        if (index == 0){
                            U = U.delete(0, 1);
                            id1 --;
                        }
                        else if (index == U.length()){
                            U = U.delete(index, index);
                            id1 --;
                        }
                        else{
                            U = U.delete(index-1,index+1);
                            id1 --;
                        }

                    }
                    
                }
            }
            

            cantidad_U = 0 ;
            cantidad_D = 0;
            for(int i = 0 ; i <= U.length() ; i++){
                if(U.charAt(i) ==  '1'){
                    cantidad_U++;
                }
    
                else{
                    cantidad_U += 2;
                }
    
            }
    
            for(int i = 0 ; i <= D.length() ; i++){
                if(U.charAt(i) ==  '1'){
                    cantidad_D++;
                }
    
                else{
                    cantidad_D += 2;
                }
    
            }
            resta = cantidad_U - cantidad_D;

        }
        

        

        

        
        resta = cantidad_R - cantidad_L;
        while(resta != 0){
            

            if(resta >= 2 || resta <= -2){
                

                if(cantidad_R > cantidad_L){
                    if(R.indexOf("2")!= -1){
                        int index = R.indexOf("2");
                        if (index == 0){
                             R = R.delete(0, 1);
                             id1 --;
                        }
                        else if (index == R.length()){
                            R = R.delete(index, index);
                            id1 --;
                        }
                        else{
                            R = R.delete(index-1,index+1);
                            id1 --;
                        }
                    }
                    else{
                        int n = 2;
                        while(n > 0){
                            int index = R.indexOf("1");
                            if (index == 0){
                                R = R.delete(0, 1);
                                id1 --;
                            }
                            else if (index == R.length()){
                                R = R.delete(index, index);
                                id1 --;
                            }
                            else{
                                R = R.delete(index-1,index+1);
                                id1 --;
                            }
                        }
                    }
                }
                

                else{
                    if(L.indexOf("2")!= -1){
                        int index = L.indexOf("2");
                        if (index == 0){
                            L = L.delete(0, 1);
                            id1 --;
                        }
                        else if (index == L.length()){
                            L = L.delete(index, index);
                            id1 --;
                        }
                        else{
                            L = L.delete(index-1,index+1);
                            id1 --;
                        }
                    }
                    else{
                        int n = 2;
                        while(n > 0){
                            int index = L.indexOf("1");
                            if (index == 0){
                                L = L.delete(0, 1);
                                id1 --;
                            }
                            else if (index == L.length()){
                                L = L.delete(index, index);
                                id1 --;
                            }
                            else{
                                L = L.delete(index-1,index+1);
                                id1 --;
                            }
                        }
                    }
                }
            }
            

            else{
                

                if(cantidad_R > cantidad_L){
                    if(R.indexOf("1")!= -1){
                        int index = R.indexOf("1");
                        if (index == 0){
                            R = R.delete(0, 1);
                            id1 --;
                        }
                        else if (index == R.length()){
                            R = R.delete(index, index);
                            id1 --;
                        }
                        else{
                            R = R.delete(index-1,index+1);
                            id1 --;
                        }
                    }
                    else{
                        int index = R.indexOf("2");
                        if (index == 0){
                            R = R.delete(0, 1);
                            id1 --;
                        }
                        else if (index == R.length()){
                            R = R.delete(index, index);
                            id1 --;
                        }
                        else{
                            R = R.delete(index-1,index+1);
                            id1 --;
                        }

                        index = L.indexOf("1");
                        if (index == 0){
                            L = L.delete(0, 1);
                            id1 --;
                        }
                        else if (index == L.length()){
                            L = L.delete(index, index);
                            id1 --;
                        }
                        else{
                            L = L.delete(index-1,index+1);
                            id1 --;
                        }

                    }
                }
                

                else{
                    if(L.indexOf("1")!= -1){
                        int index = L.indexOf("1");
                        if (index == 0){
                            L = L.delete(0, 1);
                            id1 --;
                        }
                        else if (index == L.length()){
                            L = L.delete(index, index);
                            id1 --;
                        }
                        else{
                            L = L.delete(index-1,index+1);
                            id1 --;
                        }
                    }
                    else{
                        int index = L.indexOf("2");
                        if (index == 0){
                            L = L.delete(0, 1);
                            id1 --;
                        }
                        else if (index == L.length()){
                            L = L.delete(index, index);
                            id1 --;
                        }
                        else{
                            L = L.delete(index-1,index+1);
                            id1 --;
                        }

                        index = R.indexOf("1");
                        if (index == 0){
                            R = R.delete(0, 1);
                            id1 --;
                        }
                        else if (index == R.length()){
                            R = R.delete(index, index);
                            id1 --;
                        }
                        else{
                            R = R.delete(index-1,index+1);
                            id1 --;
                        }

                    }
                    
                }
            }
            

            cantidad_R = 0 ;
            cantidad_L = 0;
            for(int i = 0 ; i <= R.length() ; i++){
                if(R.charAt(i) ==  '1'){
                    cantidad_R++;
                }
    
                else{
                    cantidad_R += 2;
                }
    
            }
    
            for(int i = 0 ; i <= L.length() ; i++){
                if(L.charAt(i) ==  '1'){
                    cantidad_L++;
                }
    
                else{
                    cantidad_L += 2;
                }
    
            }
            resta = cantidad_R - cantidad_L;


        }

        StringBuilder Us = new StringBuilder();
        StringBuilder Ds = new StringBuilder();
        StringBuilder Rs = new StringBuilder();
        StringBuilder Ls = new StringBuilder();

        if(cantidad_U == 0 && cantidad_R > 1){
            if(R.indexOf("1") != -1 && L.indexOf("1") !=  -1){
                R.append("R");
                R.append("1");
                L.append("L");
                L.append("1");
            }
        }

        else if(cantidad_R == 0 && cantidad_U > 1){
            if(U.indexOf("1") != -1 && D.indexOf("1") != -1){
                U.append("U");
                U.append("1");
                D.append("D");
                D.append("1");
            }

        }

        else{
            
            for(int i = 0;i<U.length(); i++ ){
                Us.append("U");
                Us.append(U.charAt(i));
    
            }
            for(int i = 0;i<D.length(); i++ ){
                Us.append("D");
                Us.append(D.charAt(i));
    
            }
            for(int i = 0;i<R.length(); i++ ){
                Us.append("R");
                Us.append(R.charAt(i));
    
            }
            for(int i = 0;i<L.length(); i++ ){
                Us.append(L);
                Us.append(L.charAt(i));
    
            }

        }


        

        

                    
        String[] retorno = {Integer.toString(id1),Us.toString(),Ds.toString(),Rs.toString(),Ls.toString()};
         return  retorno;
    
    }   
    
}


class Handler{

    public String[] input(StringBuilder Comandos){
        

        boolean Saltador = true;
        

        if("12".indexOf(Comandos.charAt(2)) == -1){
            Saltador = false;
        }

        

        if(Saltador){

            StringBuilder Us = new StringBuilder();
            StringBuilder Ds = new StringBuilder();
            StringBuilder Rs = new StringBuilder();
            StringBuilder Ls = new StringBuilder();

            

            char l = 'n';
            boolean EsNumero = false;

            for(int i = 0 ; i < Comandos.length() ; i ++ ){
                char letra = Comandos.charAt(i);
                if(EsNumero){
                    if(l ==  'U'){
                        Us.append(letra);
                    }
        
                    else if(l ==  'D'){
                        Ds.append(letra);
                    }
                    else if(l ==  'R'){
                        Rs.append(letra);
                    }
                    else if(l ==  'L'){
                        Ls.append(letra);
                    }
                    EsNumero = false;
                }

                else{
                    l = letra;
                    EsNumero = true;
                }

                
            }




            String[] cosa = {"error"} ;
            return cosa;
        }
        

        else{

            StringBuilder Us = new StringBuilder();
            StringBuilder Ds = new StringBuilder();
            StringBuilder Rs = new StringBuilder();
            StringBuilder Ls = new StringBuilder();
            
            for(int i = 0 ; i < Comandos.length() ; i ++ ){
                char letra = Comandos.charAt(i);
                if(letra ==  'U'){
                    Us.append("U");
                }
    
                else if(letra ==  'D'){
                    Ds.append("D");
                }
                else if(letra ==  'R'){
                    Rs.append("R");
                }
                else if(letra ==  'L'){
                    Ls.append("L");
                }
            }

            id0 id2 = new id0();
            
            
            
            return id2.movimientos(Us, Ds, Rs, Ls);
            


        }

          
    }


}