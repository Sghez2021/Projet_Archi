let etat = 1;
$(function(){
     if(etat == 1 ){
        $('.boutonjeu').append($('<button>',{class : "lebout"}).text("Jouer"));
   }
})
$(document).on("click",('.lebout') ,function(){
    etat = etat * (-1);

    if(etat == 1 ){
        $(".lebout").text("Jouer")
   } else if (etat ==-1){
    $(".lebout").text("Stop")
   
   }
});
$('.playername').keydown(function(event) {
    if (event.which === 13) { // Vérifie si la touche pressée est "Entrée" (code 13)
      var myVariable = $(this).val();  
    $.ajax({
      url: "index.php",
      type: 'POST',
      data: { myVariable: myVariable },
      dataType : 'json',
      success: function(response) {
        console.log("réponse du serveur");    
        $('#result').text(response.message);
      }
    });
}
});
