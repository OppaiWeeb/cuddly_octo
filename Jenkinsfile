pipeline {
    agent none
    stages {
        stage('Build') {
            agent {
                docker {
                    image 'alecromski/debian-xorg:latest'
                }
            }
            steps {
                sh 'mkdir -p build && cd build && cmake .. && make'
            }
        }
    }
    post {
        success {
            echo "5UCC355";
        }
        failure {
            echo "F41LUR3"
        }
    }
}
