import javax.swing.*;
import java.awt.event.*;

public class MouseEventExample {
    public static void main(String[] args) {
        JFrame f = new JFrame("Mouse Event");
        JLabel l = new JLabel("Click inside window");
        l.setBounds(100, 50, 200, 30);
        f.add(l);
        f.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                l.setText("Mouse Clicked at (" + e.getX() + ", " + e.getY() + ")");
            }
        });
        f.setSize(300, 200);
        f.setLayout(null);
        f.setVisible(true);
    }
}
