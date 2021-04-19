function Prime_number() {
    var number = document.getElementById('Number').value;
    var verify = true;
    for (var i = 2; i < number - 1; i++) {
        if (number % i == 0) {
            verify = false;
            break;
        }
    }
    if (verify) {
        alert('E primo');
    } else {
        alert('Non e primo');
    }
}