/*----------------------------------------------------------------------------*/
/*-----------------------------------HW08-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*----------------------------------Pair.java---------------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*Pair çiftlerini birlikte tutabilmek için yazılan class. 
Kodun yarısnı internetten buldum bazı fonsksiyonlarıda kendim implement ettim.*/
/*Source:(http://stackoverflow.com/questions/521171/a-java-collection-of-value-pairs-tuples)*/
/*----------------------------------------------------------------------------*/

public class Pair<T> {

    private  T left;
    private  T right;
    
    public Pair(T left, T right) {
        this.left = left;
        this.right = right;
    }
    public Pair() {
        this.left = null;
        this.right = null;
    }
    
    public T getLeft() { return left; }
    public T getRight() { return right; }
    
    public void setLeft(T a) {  left=(T)a; }
    public void setRight(T b) {  right=(T)b; }
    
    void getLeft(Object object) {}
    void getRight(Object object) {}
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
