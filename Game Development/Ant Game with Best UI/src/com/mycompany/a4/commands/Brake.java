package com.mycompany.a4.commands;
import com.mycompany.a4.GameWorld;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;

public class Brake extends Command{
	private GameWorld gw;
	
	public Brake(GameWorld gw) {
		super("Break");
		this.gw = gw;
	}
	
	public void actionPerformed(ActionEvent event) {
		gw.brake();
		System.out.println("Breaking!");
	}
}
