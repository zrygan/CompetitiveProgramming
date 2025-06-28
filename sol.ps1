param (
    [Parameter(Mandatory = $true)]
    [ValidateSet("cpp", "c", "java", "py")]
    [string]$programmingLanguage,

    [Parameter(Mandatory = $true)]
    [string]$destinationPath
)

$languageMap = @{
    "cpp"  = "main.cpp"
    "c"    = "main.c"
    "java" = "main.java"
    "py"   = "main.py"
}

$sourceFile = $languageMap[$programmingLanguage]
$ext = $sourceFile.Split('.')[1]

if ($programmingLanguage -eq "java") {
    $destinationFile = "Main.$ext"
} else {
    $destinationFile = $sourceFile
}

if (-not (Test-Path $sourceFile)) {
    Write-Error "$sourceFile not found in current directory."
    exit 1
}

# Prepend 'solutions' to the destination path
$fullDestinationPath = Join-Path -Path "." -ChildPath (Join-Path -Path "solutions" -ChildPath $destinationPath)

if (-not (Test-Path $fullDestinationPath)) {
    New-Item -ItemType Directory -Path $fullDestinationPath -Force | Out-Null
}

Copy-Item -Path $sourceFile -Destination (Join-Path $fullDestinationPath $destinationFile) -Force

Write-Host "Solution Added"
