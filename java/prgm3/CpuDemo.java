class CPU{
    int price;
        public CPU(int price){
        this.price=price;
    }
    public void displayCpu(){
        System.out.println("price :"+price);
    }

    class Processor{
        int core;
        String manufacturer;
        
        public Processor(int n,String m){
        core=n;
        manufacturer=m;
    }
    public void displayProcessor(){
        System.out.println("Core :"+core+"\nmanufacturer:" +manufacturer);
    }
    }
    static class RAM{
        String memory;
        String manufacturer;
        
        public RAM(String n,String m){
        memory=n;
        manufacturer=m;
    }
    public void displayMemory(){
        System.out.println("memory :"+memory+"\nmanufacturer:" +manufacturer);
    }

    } 
}
class CpuDemo{
    public static void main(String[] args){
        CPU c=new CPU(3000);
        CPU.Processor p= c.new Processor(7,"intel");
        CPU.RAM r=new CPU.RAM("8GB","cronex");
        c.displayCpu();
        p.displayProcessor();
        r.displayMemory();
    }
}