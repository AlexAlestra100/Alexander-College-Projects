package com.mycompany.a4;
import java.io.InputStream;
import com.codename1.media.Media;
import com.codename1.media.MediaManager;
import com.codename1.ui.Display;

/**
 * Will deploy the background sound
 * @author Alexander Alestra
 *
 */
public class BackgroundSound implements Runnable{
	private Media m;
	
	public BackgroundSound(String fileName) {
		try {
			InputStream inputStream = Display.getInstance().getResourceAsStream(getClass(), "/" + fileName);
			m = MediaManager.createMedia(inputStream,"audio/wav", this);
		}
		catch(Exception e){
			e.printStackTrace();
			System.out.println("Cannot Play Sound");
		}
	}
	public void pause() {
		m.pause();
	}
	
	public void play() {
		m.play();
	}
	
	public void run() {
		m.setTime(0);
		m.play();
	}

}