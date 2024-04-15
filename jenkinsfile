pipeline{
    agent any
    stages{
        stage('Build'){
            steps{
                sh 'echo "Building ... "'
                sh 'chmod +x scripts/linux-build.sh'
                sh 'scripts/linux-build.sh'
                archiveArtifacts artifacts: 'bin/Debug/*',fingerprint:true
            }
        }
        stage('Test'){
            steps{
                sh 'echo "Running..."'
                sh 'chmod +x scripts/linux-run.sh'
                sh 'scripts/linux-run.sh'
            }
        }

    }

}