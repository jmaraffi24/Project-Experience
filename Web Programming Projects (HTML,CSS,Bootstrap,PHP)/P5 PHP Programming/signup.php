<!DOCTYPE html>
<html>

    <!-- shared page top HTML -->

    <head>
        <title>Match</title>

        <meta charset="utf-8" />

        <!-- instructor-provided CSS and JavaScript links; do not modify -->
        <link href="heart.gif" type="image/gif" rel="shortcut icon" />
        <link href="match.css" type="text/css" rel="stylesheet" />

        <script src="http://ajax.googleapis.com/ajax/libs/prototype/1.7.0.0/prototype.js" type="text/javascript"></script>
    </head>

    <body>
        <div id="bannerarea">
            <img src="match.png" alt="banner logo" /> <br />
        </div>

        <!-- your HTML output follows -->
        <form  action="signup-submit.php" method="get">
            <fieldset>
                <legend>New User Signup:</legend>
                <strong>Name: </strong><input id="name" name="name" type="text" size="16"><br>
                <strong>Gender:</strong> 
                
                <input type="radio" name="gender" value="M"><label for="Male">Male</label>
                <input type="radio" name="gender" value="F"><label for="Female">Female</label><br>
                
                <strong>Age:</strong> <input type="text" id="age" name="age" size="6" maxlength="2"><br>
                
                <strong>Personality type:</strong> <input type="text" id="personality" name="personality" id="personality" size="6" maxlength="4"><label>(<a href="http://www.humanmetrics.com/cgi-win/JTypes2.asp">Don't know your type?</a>)</label><br>
                
                <strong>Favorite OS:</strong><select id="os" name="os">
                <option value="Windows">Windows</option>
                <option value="MacOS">MacOS</option>
                <option value="Linux">Linux</option>
                </select><br>
                
                <strong>Seeking age:</strong>
                <input type="text" name="minage" id="minage" size="6" maxlength="2" placeholder="min">
                to
                <input type="text" name="maxage" id="maxage" size="6" maxlength="2" placeholder="max"><br>
                
                <input type="submit" value="Sign Up" onsubmit="signup-submit.php">
            </fieldset>
        </form>
        

        <!-- shared page bottom HTML -->
        <div>
            <p>
                This page is for single nerds to meet and date each other!  Type in your personal information and wait for the geek love to begin!  Thank you for using our site.
            </p>

            <p>
                Results and page (C) Copyright Match Inc.
            </p>

            <ul>
                <li>
                    <a href="index.php">
                        <img src="back.gif" alt="icon" />
                        Back to front page
                    </a>
                </li>
            </ul>
        </div>

    </body>
</html>
