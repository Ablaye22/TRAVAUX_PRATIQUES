
using JuMP
using GLPK

function exemple2_PL(t)
   m = Model(GLPK.Optimizer)
   @variable(m, 0 <= x1)
   @variable(m, 0 <= x2 )


   @objective(m, Max, 5x1 + 3x2)
   @constraint(m, c1, x1 + x2 >= 2 )  
   @constraint(m, c2, 2x1 + t*x2 <= 6 )
   @constraint(m, c3, x1 + 5x2 <= 10 )


   # println("Affichage du modèle avant résolution:")
   # print(m)
   # println()

   # println("Résolution par le solveur linéaire choisi")
   optimize!(m)
   # println()

   # println("Récupération et affichage \"à la main\" d'informations précises")
   status = termination_status(m)

   if status == INFEASIBLE
      println("Le problème n'est pas réalisable")
   elseif status == OPTIMAL
      return objective_value(m)
      # println("Valeur optimale = ", objective_value(m))
      # println("Solution primale optimale :")
      # println("\t x1 = ", value(x1))
      # println("\t x2 = ", value(x2))
      # println("Coûts marginaux optimaux :")
      # println("\t c1 = ", dual(c1)) 
      # println("\t c2 = ", dual(c2))
      # println("\t c3 = ", dual(c3))
      # println("Temps de résolution :", solve_time(m))
  else
      println("Problème lors de la résolution")
  end
 
end
open("fichier_donnee.txt","w") do g
for i=-10:10
   opt = exemple2_PL(i)
   write(g,string(i)*" "*string(opt)*"\n")
end
end
