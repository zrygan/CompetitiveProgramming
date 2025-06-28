# Remove and recreate boilerplate source files

$files = @("main.cpp", "main.c", "main.java", "main.py")

# Remove existing files
foreach ($file in $files) {
    if (Test-Path $file) {
        Remove-Item $file -Force
    }
}

Set-Content -Path "main.cpp" -Value @'
#include <iostream>
using namespace std;

int main() {

}
'@

Set-Content -Path "main.c" -Value @'
#include <stdio.h>

int main() {

}
'@

Set-Content -Path "Main.java" -Value @'
public class Main {
    public static void main(String[] args) {
        
    }
}
'@

# Python (empty file)
New-Item -Path "main.py" -ItemType File -Force | Out-Null
