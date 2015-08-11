import java.io.*;

class ReadFile1 {
    public static void main(String args[]) {
        FileInputStream fin;

        try {
            fin = new FileInputStream("/etc/centos-release");
        } catch(FileNotFoundException exc) {
            System.out.println("File Not Found");
            return;
        }

        try {
            int i;
            do {
                i = fin.read();
                if(i != -1) System.out.print((char) i);
            } while(i != -1);
        } 
        catch(IOException exc) {
            System.out.println("Error reading file.");
        }

        try {
            fin.close();
        } catch(IOException exc) {
            System.out.println("Error closing file.");
        }
    }
}
