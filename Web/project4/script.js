function Prime_numbers() {
    var a = document.getElementById('number').value;
    var count = 0;
    var verify = false;
    do {
        a++;
        for (var i = 2; i < a - 1; i++) {
            if (a % i == 0) {
                verify = true;
                break;
            }
        }
        if(!verify){
            count++;
            document.write('<br>', a);
        }
        verify = false
    } while (count != 10);
}