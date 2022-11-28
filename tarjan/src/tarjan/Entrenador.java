/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarjan;

import java.util.ArrayList;

/**
 *
 * @author Cesar
 */
public class Entrenador {
    public String nombre;
    public int ncontactos;
    public ArrayList<String> contactos = new ArrayList();
    public boolean sociable;
    
    public Entrenador (int n){
        ncontactos= n;
        
    }
    
    public boolean estanConectados(String p){
        
        for (int i = 0; i< contactos.size() ; i++ ){
            if(contactos.size() != 0 && contactos.get(i)== p){
                return true;
            }
        }
        return false;
    }
    
    public void añadirContacto(String p){
        if(contactos.size() < ncontactos){
            contactos.add(p);
        }
    }
   
}
