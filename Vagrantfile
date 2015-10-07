unless Vagrant.has_plugin?("vagrant-hostmanager")
    raise "vagrant-hostmanager plugin is not installed. Please install it with vagrant plugin install vagrant-hostmanager"
end

unless Vagrant.has_plugin?("vagrant-auto_network")
    raise "vagrant-auto_network plugin is not installed. Please install it with: vagrant plugin install vagrant-auto_network"
end

Vagrant.configure("2") do |config|

    # tunables
    env_prefix  = ENV['DRUPAL_VAGRANT_ENV_PREFIX'] || 'DRUPAL_VAGRANT'
    ip          = ENV["#{env_prefix}_IP"] || '10.31.31.31'
    project     = ENV["#{env_prefix}_PROJECT"] || 'gmiw'
    # end tunables

    config.vm.box     = "ubuntu/trusty64"
    config.vm.provider "virtualbox" do |vb|
        vb.customize ["modifyvm", :id, "--memory", 1024]
    end

    path = "/var/www/sites/#{project}.local"

    config.vm.synced_folder ".", "/vagrant", :disabled => true
    config.vm.synced_folder ".", path, :nfs => true
    config.vm.hostname = "#{project}.local"
    config.vm.network :private_network, ip: ip
    config.hostmanager.enabled = true
    config.hostmanager.manage_host = true

    config.ssh.forward_agent = true
    config.ssh.insert_key = false

    config.vm.provision "ansible" do |ansible|
        ansible.playbook = "ansible/playbook.yml"
        ansible.inventory_path = "ansible/inventories/dev"
        ansible.limit = 'all'
    end

    config.vm.provision :shell, inline: <<SCRIPT
  if [[ ! -f /vagrant/cnf/settings.php ]]; then
    cp /#{path}/cnf/local.settings.php /#{path}/cnf/settings.php
  fi
  su vagrant -c 'cd #{path} && composer install && build/install.sh;'
SCRIPT
end
