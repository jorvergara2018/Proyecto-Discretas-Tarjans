/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarjan;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author Cesar
 */
public class Archivos {
    private Region miRegion;
    public ArrayList<String> misDatos;
    
    public Archivos(){
        
    }
    
    
    public void Leer(){
        
        ArrayList<String> datos = new ArrayList();
        try{
            FileReader archivo = new FileReader("Text.txt");
            BufferedReader lectura = new BufferedReader(archivo);
            String cadena;
            
            while((cadena = lectura.readLine()) != null){
                datos.add(cadena);
            }
            
        } catch(Exception Ex){};     
        misDatos = datos ;
    }
    
    public void wea(){
        for(int i = 0; i< misDatos.size(); i = i+1){
            System.out.println(""+misDatos.get(i));
        }
    }
    
}
