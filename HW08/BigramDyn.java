/*----------------------------------------------------------------------------*/
/*-----------------------------------HW08-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*-----------------------------BigramDyn.java---------------------------------*/
/*----------------------------------------------------------------------------*/


import java.io.*;
import java.util.Scanner;
@SuppressWarnings("unchecked")
public class BigramDyn<T> implements Bigram<T> {
    private T arr[];    
    private int dtp;
    private int cap;
/*Constructor..                                                              */    
    public BigramDyn(){
    
        cap=200;
        arr = (T[]) new Object[cap];
    }
/*Constructor..                                                              */    
    public BigramDyn(int dtype){
        this();
        dtp=dtype;
    }
/*Dosyadan okuma işlemin gerçekleşir.                                        */
    
    @Override
    public void readFile(String filename)throws IOException{
        try{
            Scanner sc = new Scanner(new File(filename));
            int k = 0;

                while(sc.hasNext())
                {   
                    sc.next();

                    ++k;
                }

            sc.close();
            cap=k;
        }
        catch(IOException e){
            
        }
        Scanner scanner = new Scanner(new File(filename));
        int i = 0;
        while(scanner.hasNext())
        {
           arr[i++] = (T) scanner.next();
        }
        cap=i;
        
        scanner.close();
    }
/*Verilen dizi içindeki gram sayısını döndürür.                              */
    
    @Override
    public int numGrams(){
        return cap-1;
    }
/*Verilen ikili değerin gram sayısını döndürür.                              */
    
    @Override
    public int numOfGrams(T a,T b){
    
        Object arrT[] = new Object[2];
        
        arrT[0]=a;
        arrT[1]=b;
        
        int count=0;
        
        for (int i = 0; i < cap; i++) {
            
            if(arr[i].toString().equals(arrT[0].toString()) && arr[i+1].toString().equals(arrT[1].toString())) {
                ++count;
            }
        }
        return count; 
    }
/*Gramları azalan sırada olmak üzere gramları sıralar..                      */
    
    @Override
    public String toString(){
        Pair tmp;
        int arrcount=0;
        int datcount=0;
        Pair[] array = new Pair[cap];
        StringBuilder res = new StringBuilder();
        int[] dat = new int[cap];
        for(int i = 0; i < cap-1; ++i){
            if(!isAlreadyHaveDat(dat,numOfGrams(arr[i], arr[i+1]))){
                
                dat[datcount++] = numOfGrams(arr[i], arr[i+1]);
            }
            tmp = new Pair(arr[i],arr[i+1]);
            if(!isAlreadyHaveArray(array, tmp))
            {
                array[arrcount++] = tmp;
            }
        }
        for(int i=0; i<cap;++i){       
            int t;
            for(int m=0; m<cap-1;++m){
                if(dat[m]<dat[m+1]){
                    t=dat[m];
                    dat[m]=dat[m+1];
                    dat[m+1]=t;
                    tmp= new Pair(array[m].getLeft(),array[m].getRight());
                    array[m]=new Pair(array[m+1].getLeft(),array[m+1].getRight());
                    array[m+1]=tmp;
              }
          }
        }
        for (int i = 0; i <datcount; i++) {
            for (int j = 0; j < arrcount; j++) {
                if(numOfGrams((T)array[j].getLeft(),(T)array[j].getRight())==dat[i]){
                    
                    res.append(array[j].getLeft()+"--"+array[j].getRight()+"\n");
                    
                }
            }
        }
        return res.toString();
    }    
    boolean isAlreadyHaveDat(int[] dat, int elem){
        for(int i=0 ; i< dat.length;++i){
            if(elem == dat[i])
                return true;
        }
        return false;
    }
    boolean isAlreadyHaveArray(Pair[] arr,Pair elem){
        if(elem == null || arr==null)
            return false;
        for(int i =0; i < arr.length; ++i){
            if(arr[i] == null)
                return false;
            if( elem.getLeft().equals(arr[i].getLeft()) && elem.getRight().equals(arr[i].getRight()))
                return true;
        }
        return false;
    }
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
