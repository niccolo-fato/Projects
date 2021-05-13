function validate(){
    let nome = document.getElementById('name').value;
    let cognome = document.getElementById('surname').value;
    let data1 = document.getElementById('data1').value;
    let data2 = document.getElementById('data2').value;
    if( nome == '' || cognome == ''){
        alert('Inserire nome e cognome validi');
    }
    if(data1<data2){
        alert('Date inserite valide');
    }else{
        alert('Date inserite non valide');
    }
}