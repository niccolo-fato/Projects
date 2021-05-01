function validate() {
    let input = document.getElementById('password').value;
    let verify = true;
    if(!input.match(/(?=.*[0-9])/)) {
      document.getElementById("Error").innerHTML += '*Non ci sono numeri<br>';
      verify = false;
    } 
    if(!input.match(/(?=.*[A-Z])/)) {
        document.getElementById("Error").innerHTML += '*Non ci sono lettere maiuscole<br>';
        verify = false;
      } 
    if(!input.match(/(?=.*[!@#$%^&*])/)) {
        document.getElementById("Error").innerHTML += '*Non ci sono caratteri speciali<br>';
        verify = false;
      } 
    if(!input.match(/.{8}/)) {
        document.getElementById("Error").innerHTML += '*La password e troppo corta';
        verify = false;
      } 
    if(verify){
        alert('Password inserita correttamente'); 
    }
  }