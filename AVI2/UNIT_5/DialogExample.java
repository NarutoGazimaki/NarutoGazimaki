import javax.swing.*;

public class DialogExample {
    public static void main(String[] args) {
        JFrame f = new JFrame("Dialog Example");
        JDialog d = new JDialog(f, "Dialog Box", true);
        JLabel l = new JLabel("This is a dialog");
        l.setBounds(30, 30, 150, 30);
        d.add(l);
        d.setSize(200, 150);
        d.setLayout(null);
        d.setVisible(true);
    }
}



✍️ 5. JTextField and JTextArea
/*import javax.swing.*;

public class TextExample {
    public static void main(String[] args) {
        JFrame f = new JFrame("Text Fields");
        JTextField tf = new JTextField("Enter name");
        JTextArea ta = new JTextArea("Enter details here...");
        tf.setBounds(50, 50, 150, 30);
        ta.setBounds(50, 100, 200, 100);
        f.add(tf); f.add(ta);
        f.setSize(300, 250);
        f.setLayout(null);
        f.setVisible(true);
    }
}
    */

