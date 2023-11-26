/*
javac App.java 
java App 
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class App extends JFrame {
    private int xPrev = -1, yPrev = -1;

    public App() {
        super("Simple Drawing Application");

        JPanel drawPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                this.setBackground(Color.WHITE);
            }
        };

        drawPanel.addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                if (xPrev != -1 && yPrev != -1) {
                    Graphics g = drawPanel.getGraphics();
                    g.drawLine(xPrev, yPrev, e.getX(), e.getY());
                }
                xPrev = e.getX();
                yPrev = e.getY();
            }
        });

        drawPanel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseReleased(MouseEvent e) {
                xPrev = -1;
                yPrev = -1;
            }
        });

        this.add(drawPanel);
        this.setSize(640, 480);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new App());
    }
}
