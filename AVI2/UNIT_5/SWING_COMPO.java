import javax.swing.*;

public class SWING_COMPO {
    public static void main(String[] args) {
        JFrame f = new JFrame("Component Hierarchy");
        JButton b = new JButton("Click");
        JLabel l = new JLabel("Label");
        JTextField tf = new JTextField("Text");
        b.setBounds(50, 50, 80, 30);
        l.setBounds(50, 90, 80, 30);
        tf.setBounds(50, 130, 100, 30);
        f.add(b); f.add(l); f.add(tf);
        f.setSize(250, 250);
        f.setLayout(null);
        f.setVisible(true);
    }
}
