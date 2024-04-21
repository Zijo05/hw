<?php
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['submit_form'])) {
    // Handle form submission
    $ime = $_POST['ime'];
    $email = $_POST['email'];
    $poruka = $_POST['poruka'];

    // Server-side validation
    $greske = array();
    if (empty($ime)) {
        $greske[] = "Upisite Vase ime";
    }
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $greske[] = "Upisite Vas email";
    }
    if (empty($poruka)) {
        $greske[] = "Napisite Vasu poruku";
    }

    if (!empty($greske)) {
        // Display greske and redirect back to the form
        echo "<h2>Greske:</h2>";
        foreach ($greske as $greska) {
            echo "<p class='greska'>$greska</p>";
        }
        echo "<p><a href='index.html'>Vrati se na pocetnu</a></p>";
    } else {
        // Save the data to a text file
        $podaci = "Ime: $ime\nEmail: $email\nPoruka: $poruka\n\n";
        $datoteka = 'kontakti.txt';
        file_put_contents($datoteka, $podaci, FILE_APPEND | LOCK_EX);

        // Confirmation message
        echo "<h2>Hvala Vam, $ime!</h2>";
        echo "<p>Vaša poruka \"$poruka\" je poslata. Kontaktirat cemo Vas na $email uskoro.</p>";
        echo "<button onclick='location.href=\"index.html\"'>Vrati se na pocetnu</button>";
    }
} elseif ($_SERVER["REQUEST_METHOD"] == "GET" && isset($_GET['prikazi_kontakte'])) {
    // Handle displaying contacts
    $datoteka = 'kontakti.txt';

    if (file_exists($datoteka)) {
        $kontakti = file_get_contents($datoteka);
        echo "<h2>Svi kontakti:</h2>";
        echo "<pre>$kontakti</pre>";
        echo "<button onclick='location.href=\"index.html\"'>Vrati se na pocetnu</button>";
    } else {
        echo "<p>No contacts found.</p>";
        echo "<button onclick='location.href=\"index.html\"'>Vrati se na pocetnu</button>";
    }
} else {
    // Redirect back to the form if accessed directly or no action specified
    header("Location: index.html");
    exit();
}
?>
