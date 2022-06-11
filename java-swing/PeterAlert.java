import javax.swing.JOptionPane;
import javax.swing.ImageIcon;
import java.io.IOException;

public enum PeterAlert {
	;

	private static final ImageIcon PETER_IMAGE;
	
	static {
		PETER_IMAGE = new ImageIcon(PeterAlert.class.getResource("peter.gif"));
	}

	public static void showPeterAlert(){
		JOptionPane.showMessageDialog(null, "", "Peter Alert", JOptionPane.INFORMATION_MESSAGE, PETER_IMAGE);
	}
}