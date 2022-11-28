/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarjan;

import java.util.ArrayList;
import java.util.List;
import static tarjan.TarjanSccSolverAdjacencyList.addEdge;
import static tarjan.TarjanSccSolverAdjacencyList.createGraph;

/**
 *
 * @author Cesar
 */
public class Region {
    public ArrayList<Entrenador> Entrenadores;
    public int nEntrenadores;
    List<List<Integer>> graph;
    public Region(){
        Entrenadores = new ArrayList();
        graph = createGraph(nEntrenadores);
    }
    
    public void addEntrenadores(Entrenador En){
       if(Entrenadores.size() < nEntrenadores){
           Entrenadores.add(En); 
       } 
    }
        
    public Entrenador getEntrenador(int i){
        return Entrenadores.get(i);
    }
    
    public void crearConexion(){
        for(int i = 0; i < Entrenadores.size(); i++){
            for(int k = i+1; k < Entrenadores.size(); k++ ){
                for(int j = 0; j < Entrenadores.get(i).ncontactos ; j++ ){
                if( Entrenadores.get(i).estanConectados(Entrenadores.get(k).nombre) == true && Entrenadores.get(k).sociable == true){
                    addEdge(graph, j, k);
                }
            }
          }
        }
        
    }
    
}
