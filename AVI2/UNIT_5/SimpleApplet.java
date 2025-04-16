import java.applet.*;
import java.awt.*;

/*
<applet code="SimpleApplet.class" width="300" height="200"></applet>
*/

public class SimpleApplet extends Applet {
    public void init() {
        System.out.println("Applet initialized");
    }

    public void start() {
        System.out.println("Applet started");
    }

    public void paint(Graphics g) {
        g.drawString("Hello from Applet", 100, 100);
    }

    public void stop() {
        System.out.println("Applet stopped");
    }

    public void destroy() {
        System.out.println("Applet destroyed");
    }
}
