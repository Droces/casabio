<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Composite;

use PHPExiftool\Driver\AbstractTag;

class FileNumber extends AbstractTag
{

    protected $Id = 'FileNumber';

    protected $Name = 'FileNumber';

    protected $FullName = 'Composite';

    protected $GroupName = 'Composite';

    protected $g0 = 'Composite';

    protected $g1 = 'Composite';

    protected $g2 = 'Other';

    protected $Type = '?';

    protected $Writable = true;

    protected $Description = 'File Number';

    protected $local_g2 = 'Image';

}
