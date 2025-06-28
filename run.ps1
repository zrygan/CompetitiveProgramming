param (
    [Parameter(Mandatory = $true)]
    [ValidateSet("cpp", "c", "java", "py")]
    [string]$pl
)

switch ($pl) {
    "cpp" {
        if (Test-Path "main.cpp") {
            cl /EHsc main.cpp
            if (Test-Path "main.exe") {
                ./main.exe
                Remove-Item main.exe, main.obj -Force
            }
        } else {
            Write-Error "main.cpp not found."
        }
    }
    "c" {
        if (Test-Path "main.c") {
            cl main.c
            if (Test-Path "main.exe") {
                ./main.exe
                Remove-Item main.exe, main.obj -Force
            }
        } else {
            Write-Error "main.c not found."
        }
    }
    "java" {
        if (Test-Path "Main.java") {
            javac Main.java
            if ($LASTEXITCODE -eq 0) {
                java Main
                Remove-Item Main.class -Force
            }
        } else {
            Write-Error "Main.java not found."
        }
    }
    "py" {
        if (Test-Path "main.py") {
            python main.py
        } else {
            Write-Error "main.py not found."
        }
    }
}
