<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Photoshop;

use PHPExiftool\Driver\AbstractTag;

class EPSOptions extends AbstractTag
{

    protected $Id = 1021;

    protected $Name = 'EPSOptions';

    protected $FullName = 'Photoshop::Main';

    protected $GroupName = 'Photoshop';

    protected $g0 = 'Photoshop';

    protected $g1 = 'Photoshop';

    protected $g2 = 'Image';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'EPS Options';

}
